.setcpu "65816"
.segment "CODE"
.org $CE31
map_control_0fce31:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
