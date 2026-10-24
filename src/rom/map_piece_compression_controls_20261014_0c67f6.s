.setcpu "65816"
.segment "CODE"
.org $67F6
map_control_0c67f6:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
