.setcpu "65816"
.segment "CODE"
.org $EDA8
map_control_0feda8:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
