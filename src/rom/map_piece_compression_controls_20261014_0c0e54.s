.setcpu "65816"
.segment "CODE"
.org $0E54
map_control_0c0e54:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $CB ; row-distance/count
