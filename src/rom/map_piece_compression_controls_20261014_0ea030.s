.setcpu "65816"
.segment "CODE"
.org $A030
map_control_0ea030:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
