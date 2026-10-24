.setcpu "65816"
.segment "CODE"
.org $A039
map_control_0da039:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
