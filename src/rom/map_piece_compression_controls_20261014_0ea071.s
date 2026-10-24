.setcpu "65816"
.segment "CODE"
.org $A071
map_control_0ea071:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
