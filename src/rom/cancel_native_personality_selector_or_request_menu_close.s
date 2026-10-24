; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-personality-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

highlight_native_menu_actor_sprite_palette = $1EFD
publish_native_menu_twenty_nine_column_tile_strip = $C76D57
request_native_menu_close_and_clear_auxiliary_page_flag = $305A
routine_c01baf = $1BAF

.segment "CODE"
.org $3043
cancel_native_personality_selector_or_request_menu_close:
    .a8
    lda #$20
    bit a:$A212
    beq request_native_menu_close_and_clear_auxiliary_page_flag
    pha
    jsr highlight_native_menu_actor_sprite_palette
    pla
    trb a:$A212
    jsr routine_c01baf
    jsl f:publish_native_menu_twenty_nine_column_tile_strip
    rts
