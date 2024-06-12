#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to handle diary entries
void mental_health_diary(char *date, char *feeling) {
    // Array of daily quotes
    const char *quotes[] = {
        "'I found that with depression, one of the most important things you can realize is that you’re not alone. You’re not the first to go through it, you’re not gonna be the last to go through it,' — Dwayne The Rock Johnson",
        "‘The advice I’d give to somebody that’s silently struggling is, you don’t have to live that way. You don’t have to struggle in silence. You can be un-silent. You can live well with a mental health condition, as long as you open up to somebody about it, because it’s really important you share your experience with people so that you can get the help that you need.’ — Demi Lovato",
        "‘Mental health needs a great deal of attention. It’s the final taboo and it needs to be faced and dealt with.’ — Adam Ant",
        "‘Be proud of who you are, and not ashamed of how someone else sees you.’",
        "‘Mental health needs a great deal of attention. It’s the final taboo and it needs to be faced and dealt with.’ — Adam Ant",
        "‘You are the one thing in this world, above all other things, that you must never give up on. When I was in middle school, I was struggling with severe anxiety and depression and the help and support I received from my family and a therapist saved my life. Asking for help is the first step. You are more precious to this world than you’ll ever know.’ — Lili Reinhart",
        "‘Part of my identity is saying no to things I don’t want to do… I check in with myself throughout the day and I say, ‘Do I really want to do this?’ and if the answer is no, then I don’t do it. And you shouldn’t either.’ — Lady Gaga",
        "‘Above all, be true to yourself, and if you cannot put your heart in it, take yourself out of it.’",
        "‘If you’re searching for that one person that will change your life, take a look in the mirror.’",
        "‘You yourself, as much as anybody in the entire universe, deserve your love and affection.’",
        "‘You are free, you are powerful, you are good, you are love, you have value, you have a purpose. All is well.’",
        "‘Put yourself at the top of your to-do list every single day and the rest will fall into place.’",
        "'Eat like you love yourself. Move like you love yourself. Speak like you love yourself. Act like your love yourself. Love yourself.'",
        "‘One day I woke up and realised I was not made for anyone, I was made for me. I am my own.’",
        "‘There’s no need to be perfect to inspire others. Let others get inspired by how you deal with your imperfections.’",
        "‘Confidence is the ability to feel beautiful, without needing someone to tell you.’",
        "‘In order to love who you are, you cannot hate the experiences that shaped you.’",
        "‘Regardless of how anyone else feels about me, I am going to choose to love myself today.’",
        "‘When I accept myself just as I am, I am freed from the burden of needing you to accept me.’",
        "‘There is no sense in punishing your future for the mistakes of your past. Forgive yourself, grow from it, and then let it go.’",
        "‘Beauty begins the moment you decide to be yourself.’",
        "‘Falling in love with yourself first doesn’t make you vain or selfish. It makes you indestructible.’",
        "‘Self love. It doesn’t mean that everyone will treat you the way you deserve to be treated. It means that you won’t let them change the way you see yourself; nor will you stick around for them to destroy you.’",
        "‘If you don’t love yourself, nobody will. Not only that, you won’t be good at loving anyone else. Loving starts with the self.’",
        "‘Demonstrate love by giving it, unconditionally, to yourself. And as you do, you will attract others into your life who will love you without conditions.'",
        "'Never give up on anyone. And that includes not giving up on yourself.'",
        "‘I am not looking to escape my darkness, I’m learning to love myself here.’",
        "‘You’re a work of art. Not everyone will understand you, but the ones who do, will never forget about you.’",
        "‘Inner peace begins the moment you choose not to allow another person or event to control your emotions.’",
        "‘A flower does not think of competing with the flower next to it. It just blooms.’",
        "'Be yourself; everyone else is already taken.' - Oscar Wilde",
        "'To live is the rarest thing in the world. Most people exist, that is all.' - Oscar Wilde",
        "'Live as if you were to die tomorrow. Learn as if you were to live forever.' - Mahatma Gandhi",
        "'No one can make you feel inferior without your consent.' - Eleanor Roosevelt",
        "'The only person you are destined to become is the person you decide to be.' - Ralph Waldo Emerson",
        "'Do what you feel in your heart to be right - for you'll be criticized anyway.' - Eleanor Roosevelt",
        "'Life isn't about finding yourself. Life is about creating yourself.' - George Bernard Shaw",
        "'Success is not final, failure is not fatal: it is the courage to continue that counts.' - Winston Churchill",
        "'If you want to lift yourself up, lift up someone else.' - Booker T. Washington",
        "'The best way to predict the future is to create it.' - Peter Drucker",
        "'The only way to do great work is to love what you do.' - Steve Jobs",
        "'If you want to live a happy life, tie it to a goal, not to people or things.' - Albert Einstein",
        "'The only limit to our realization of tomorrow will be our doubts of today.' - Franklin D. Roosevelt",
        "'The future belongs to those who believe in the beauty of their dreams.' - Eleanor Roosevelt",
        "'Kind words can be short and easy to speak, but their echoes are truly endless.' - Mother Teresa",
    };
    int num_quotes = sizeof(quotes) / sizeof(quotes[0]);

    // Seed the random number generator
    srand((unsigned) time(NULL));
    int random_index = rand() % num_quotes;

    // Print the selected quote
    printf("Daily Quote: %s\n", quotes[random_index]);

    // Print the provided date and feeling
    printf("Enter Today's Date (ex. Jan 1, 2000): %s\n", date);
    printf("Enter how you are feeling: %s\n", feeling);

    // Open the file to append the entry
    FILE *fp = fopen("Diary.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s|%s\n", date, feeling);
        fclose(fp);
    } else {
        printf("Error opening file for writing.\n");
    }
}

int main(int argc, char **argv) {
    if (argc == 3) {
        // Call the diary function with the provided arguments
        mental_health_diary(argv[1], argv[2]);
    } else {
        // Print usage instructions if incorrect arguments are provided
        printf("Usage: %s <date> <feeling>\n", argv[0]);
    }
    return 0;
}