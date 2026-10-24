.setcpu "65816"
.segment "CODE"
.org $A091
map_control_0ea091:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $36 ; distance low bit/count
