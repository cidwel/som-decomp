.setcpu "65816"
.segment "CODE"
.org $A15B
map_control_0ea15b:
    .byte $EA ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
