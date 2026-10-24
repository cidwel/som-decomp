.setcpu "65816"
.segment "CODE"
.org $DDFD
map_control_0eddfd:
    .byte $EA ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
