.setcpu "65816"
.segment "CODE"
.org $0E5E
map_control_0c0e5e:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $CB ; row-distance/count
