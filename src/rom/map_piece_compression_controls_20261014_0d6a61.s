.setcpu "65816"
.segment "CODE"
.org $6A61
map_control_0d6a61:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
