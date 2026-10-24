.setcpu "65816"
.segment "CODE"
.org $83F6
map_control_0d83f6:
    .byte $ED ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
