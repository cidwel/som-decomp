; Recovered Secret of Mana USA routine; behaviour documented in docs/settings-actor-text-bridge.md.
.setcpu "65816"
.smart
.a8
.i16

publish_native_menu_actor_text_and_palette = $2082

.segment "CODE"
.org $2AFA
long_call_native_menu_actor_text_and_palette:
    jsr publish_native_menu_actor_text_and_palette
    rtl
