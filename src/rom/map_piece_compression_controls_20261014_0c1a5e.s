.setcpu "65816"
.segment "CODE"
.org $1A5E
map_control_0c1a5e:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
