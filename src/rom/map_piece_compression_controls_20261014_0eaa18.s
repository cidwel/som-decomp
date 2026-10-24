.setcpu "65816"
.segment "CODE"
.org $AA18
map_control_0eaa18:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
