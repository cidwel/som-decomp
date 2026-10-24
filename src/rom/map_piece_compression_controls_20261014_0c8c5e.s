.setcpu "65816"
.segment "CODE"
.org $8C5E
map_control_0c8c5e:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
