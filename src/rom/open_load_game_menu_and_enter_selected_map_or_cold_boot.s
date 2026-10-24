; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-cold-caller.md.
.setcpu "65816"
.smart
.a8
.i16

clear_direct_page_and_party_workspace_before_load_game_menu = $0FAA
jump_to_cold_boot = $C10010
public_boss_random_initialization_jump = $C2000F
request_audio_macro_eighty_with_parameter_thirty_two = $0FD5
routine_00800c = $800C
routine_c01d97 = $C01D97

.segment "CODE"
.org $00C9
open_load_game_menu_and_enter_selected_map_or_cold_boot:
    php
    sep #$20
    .a8
    lda #$00
    sta f:$0019FD
    sta f:$7ECFF6
    lda f:$7EA212
    .a8
    ora #$10
    sta f:$7EA212
    jsr clear_direct_page_and_party_workspace_before_load_game_menu
    .a8
    lda #$FF
    sta f:$00011F
    .a8
    lda #$06
    jsl f:routine_c01d97
    rep #$20
    lda f:$7EA213
    .a16
    cmp #$0707
    beq open_load_game_menu_and_enter_selected_map_or_cold_boot_c0010e
    jsr request_audio_macro_eighty_with_parameter_thirty_two
    lda f:$7EA23C
    jsl f:public_boss_random_initialization_jump
    lda f:$7EA25A
    plp
    jml f:routine_00800c
open_load_game_menu_and_enter_selected_map_or_cold_boot_c0010e:
    plp
    jml f:jump_to_cold_boot
