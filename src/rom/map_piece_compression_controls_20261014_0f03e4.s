.setcpu "65816"
.segment "CODE"
.org $03E4
map_control_0f03e4:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
