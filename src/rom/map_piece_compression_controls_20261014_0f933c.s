.setcpu "65816"
.segment "CODE"
.org $933C
map_control_0f933c:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
