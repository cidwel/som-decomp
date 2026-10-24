.setcpu "65816"
.segment "CODE"
.org $D54C
map_control_0dd54c:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $6D ; distance low bit/count
