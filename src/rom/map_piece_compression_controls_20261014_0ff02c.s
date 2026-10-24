.setcpu "65816"
.segment "CODE"
.org $F02C
map_control_0ff02c:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
