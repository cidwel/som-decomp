.setcpu "65816"
.segment "CODE"
.org $834C
map_control_0d834c:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
