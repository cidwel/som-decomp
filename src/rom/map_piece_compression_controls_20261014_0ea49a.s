.setcpu "65816"
.segment "CODE"
.org $A49A
map_control_0ea49a:
    .byte $EA ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
