.setcpu "65816"
.segment "CODE"
.org $BCED
map_control_0ebced:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
