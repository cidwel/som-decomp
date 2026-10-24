.setcpu "65816"
.segment "CODE"
.org $0D54
map_control_0d0d54:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $B1 ; row-distance/count
