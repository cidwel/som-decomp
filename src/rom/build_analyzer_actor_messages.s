; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_message_queue_line = $5CCF
append_actor_name_message_token = $5C06
append_message_byte_decimal = $5C38
append_message_word_decimal = $5C6C
append_rom_message_text = $5C2A
replace_message_prefix_with_dialogue_marker = $5A7F

object_max_hp = $E184
object_hp = $E182
object_mp = $E186
object_max_mp = $E187
object_original_id = $E1E7
object_actor_kind = $E1FB
object_exp_reward = $E18D
object_gold_reward = $E1C8
object_element_weakness = $E1A1
message_queue_buffer = $FE00

.segment "CODE"
.org $599D
build_analyzer_actor_messages:
    lda a:object_original_id,X
    .a8
    cmp #$83
    bcc build_analyzer_actor_messages_c059a5
    rtl
build_analyzer_actor_messages_c059a5:
    phy
    phx
    jsr allocate_message_queue_line
    jsr replace_message_prefix_with_dialogue_marker
    .i16
    ldx #$628C
    jsr append_rom_message_text
    ldx $85
    rep #$20
    lda a:object_hp,X
    sta $D0
    sep #$20
    jsr append_message_word_decimal
    .a8
    lda #$C1
    sta a:message_queue_buffer,Y
    iny
    ldx $85
    rep #$20
    lda a:object_max_hp,X
    sta $D0
    sep #$20
    jsr append_message_word_decimal
    jsr allocate_message_queue_line
    jsr replace_message_prefix_with_dialogue_marker
    .i16
    ldx #$6290
    jsr append_rom_message_text
    ldx $85
    lda a:object_mp,X
    sta $D0
    jsr append_message_byte_decimal
    .a8
    lda #$C1
    sta a:message_queue_buffer,Y
    iny
    ldx $85
    lda a:object_actor_kind,X
    php
    lda a:object_max_mp,X
    sta $D0
    jsr append_message_byte_decimal
    plp
    bmi build_analyzer_actor_messages_c05a36
    jsr allocate_message_queue_line
    jsr replace_message_prefix_with_dialogue_marker
    .i16
    ldx #$62D2
    jsr append_rom_message_text
    ldx $85
    rep #$20
    lda a:object_exp_reward,X
    sta $D0
    sep #$20
    jsr append_message_word_decimal
    jsr allocate_message_queue_line
    jsr replace_message_prefix_with_dialogue_marker
    ldx $85
    rep #$20
    lda a:object_gold_reward,X
    sta $D0
    sep #$20
    jsr append_message_word_decimal
    .i16
    ldx #$62D7
    jsr append_rom_message_text
build_analyzer_actor_messages_c05a36:
    ldx $85
    lda a:object_element_weakness,X
    sta $D8
    .i16
    ldy #$5DDB
    sty $B4
    .a8
    lda #$07
    sta $D0
    .a8
    lda #$80
    sta $CC
    .a8
    lda #$C0
    sta $B6
build_analyzer_actor_messages_c05a4e:
    lda $CC
    bit $D8
    bne build_analyzer_actor_messages_c05a5d
build_analyzer_actor_messages_c05a54:
    dec $D0
    lsr $CC
    bne build_analyzer_actor_messages_c05a4e
    ply
    plx
    rtl
build_analyzer_actor_messages_c05a5d:
    .a8
    lda #$00
    xba
    lda $D0
    asl
    phy
    tay
    rep #$20
    lda [$B4],Y
    sep #$20
    ply
    tax
    jsr allocate_message_queue_line
    jsr replace_message_prefix_with_dialogue_marker
    phx
    ldx $85
    jsr append_actor_name_message_token
    plx
    jsr append_rom_message_text
    bra build_analyzer_actor_messages_c05a54
