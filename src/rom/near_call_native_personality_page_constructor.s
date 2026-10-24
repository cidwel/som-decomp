; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-normal-category-menu.md.
.setcpu "65816"
.smart
.a8
.i16

construct_native_hero_personality_page = $C76BE3

.segment "CODE"
.org $2A9F
near_call_native_personality_page_constructor:
    jsl f:construct_native_hero_personality_page
    rts
