.setcpu "65816"
.segment "CODE"
.org $67DD
map_control_0c67dd:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
