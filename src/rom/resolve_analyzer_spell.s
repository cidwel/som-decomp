; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_max_hp = $E184
object_analyzer_row_index = $E1CA
object_id = $E180

build_analyzer_actor_messages = $C0599D

.segment "CODE"
.org $EC00
resolve_analyzer_spell:
    ldx $85
    lda a:object_id,X
    .a8
    cmp #$EA
    beq resolve_analyzer_spell_c8ec0e
    jsl f:build_analyzer_actor_messages
    rts
resolve_analyzer_spell_c8ec0e:
    lda a:object_analyzer_row_index,X
    sta f:$004202
    .a8
    lda #$05
    sta f:$004203
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    tax
    sep #$20
    lda f:$D03A51,X
    .a8
    and #$0F
    cmp $9D
    beq resolve_analyzer_spell_c8ec33
    bcs resolve_analyzer_spell_c8ec3a
resolve_analyzer_spell_c8ec33:
    ldx $85
    .a8
    lda #$FF
    sta a:object_max_hp,X
resolve_analyzer_spell_c8ec3a:
    rts
