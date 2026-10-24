.setcpu "65816"
.segment "CODE"
.org $A4B1
map_control_0ea4b1:
    .byte $EA ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
