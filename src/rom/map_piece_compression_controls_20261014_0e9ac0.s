.setcpu "65816"
.segment "CODE"
.org $9AC0
map_control_0e9ac0:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AD ; row-distance/count
