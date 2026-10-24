.setcpu "65816"
.segment "CODE"
.org $B843
map_control_0db843:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $BD ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
