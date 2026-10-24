; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-map-entry-requests.md.
.setcpu "65816"
.smart
.a8
.i16

routine_01e76d = $1E76D

.segment "CODE"
.org $BEAA
request_actual_map_entry_event_and_restore_deferred_party_actor:
    sep #$20
    lda f:$7ECF00
    bne request_actual_map_entry_event_and_restore_deferred_party_actor_c0bec8
    lda $ED
    bpl request_actual_map_entry_event_and_restore_deferred_party_actor_c0bec8
    .a8
    and #$7F
    sta $ED
    lda f:$7EE882
    sta f:$7EEC82
    .a8
    lda #$04
    sta f:$7EEC83
request_actual_map_entry_event_and_restore_deferred_party_actor_c0bec8:
    lda $B8
    .a8
    and #$03
    .a8
    eor #$FF
    sec
    .a8
    adc #$C0
    sta $4D
    lda $B8
    .a8
    and #$04
    bne request_actual_map_entry_event_and_restore_deferred_party_actor_c0beda
request_actual_map_entry_event_and_restore_deferred_party_actor_c0bed9:
    rts
request_actual_map_entry_event_and_restore_deferred_party_actor_c0beda:
    lda $E8
    bmi request_actual_map_entry_event_and_restore_deferred_party_actor_c0bed9
    .a8
    and #$03
    .a8
    cmp #$03
    bne request_actual_map_entry_event_and_restore_deferred_party_actor_c0bee5
    rts
request_actual_map_entry_event_and_restore_deferred_party_actor_c0bee5:
    rep #$30
    lda $DC
    asl
    tax
    lda f:$C84000,X
    tax
    lda f:$C80000,X
    .a16
    and #$0FFF
    jsl f:routine_01e76d
    rts
