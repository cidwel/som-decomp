; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16

consume_boss_byte34_bit0_or_return_negative_status = $0501
invoke_state_callback = $36B3
test_boss_negative_status_word = $34B0

.segment "CODE"
.org $362D
resolve_boss_hurt_death_timer_and_animation_completion:
    lda a:$004A,X
    beq resolve_boss_hurt_death_timer_and_animation_completion_c23638
    jsr invoke_state_callback
    bcc resolve_boss_hurt_death_timer_and_animation_completion_c23638
    rts
resolve_boss_hurt_death_timer_and_animation_completion_c23638:
    lda a:$0082,X
    .a16
    cmp #$0002
    beq resolve_boss_hurt_death_timer_and_animation_completion_c2366f
    jsr consume_boss_byte34_bit0_or_return_negative_status
    bcc resolve_boss_hurt_death_timer_and_animation_completion_c2367c
    lda a:$0082,X
    bne resolve_boss_hurt_death_timer_and_animation_completion_c2364f
    jsr test_boss_negative_status_word
    bcc resolve_boss_hurt_death_timer_and_animation_completion_c2367c
resolve_boss_hurt_death_timer_and_animation_completion_c2364f:
    .a16
    lda #$0002
    sta a:$0082,X
    stz a:$002D,X
    lda a:$00BA,X
    beq resolve_boss_hurt_death_timer_and_animation_completion_c23664
    jsr invoke_state_callback
    ldx $87
    bra resolve_boss_hurt_death_timer_and_animation_completion_c23667
resolve_boss_hurt_death_timer_and_animation_completion_c23664:
    lda a:$00BE,X
resolve_boss_hurt_death_timer_and_animation_completion_c23667:
    sta a:$00B0,X
    stz a:$00B2,X
    sec
    rts
resolve_boss_hurt_death_timer_and_animation_completion_c2366f:
    jsr test_boss_negative_status_word
    bcc resolve_boss_hurt_death_timer_and_animation_completion_c2367c
    .a16
    lda #$0004
    sta a:$0094,X
    clc
    rts
resolve_boss_hurt_death_timer_and_animation_completion_c2367c:
    lda a:$0014,X
    beq resolve_boss_hurt_death_timer_and_animation_completion_c2368a
    lda a:$0096,X
    cmp a:$0014,X
    bcc resolve_boss_hurt_death_timer_and_animation_completion_c2368a
    rts
resolve_boss_hurt_death_timer_and_animation_completion_c2368a:
    lda a:$004A,X
    bne resolve_boss_hurt_death_timer_and_animation_completion_c236b1
    lda a:$0082,X
    beq resolve_boss_hurt_death_timer_and_animation_completion_c236a5
    lda a:$007C,X
    .a16
    bit #$0001
    bne resolve_boss_hurt_death_timer_and_animation_completion_c236a5
    lda a:$00AD,X
    cmp a:$002D,X
    bcc resolve_boss_hurt_death_timer_and_animation_completion_c236a5
    rts
resolve_boss_hurt_death_timer_and_animation_completion_c236a5:
    lda a:$0014,X
    bne resolve_boss_hurt_death_timer_and_animation_completion_c236b1
    lda a:$009E,X
    bne resolve_boss_hurt_death_timer_and_animation_completion_c236b1
    sec
    rts
resolve_boss_hurt_death_timer_and_animation_completion_c236b1:
    clc
    rts
