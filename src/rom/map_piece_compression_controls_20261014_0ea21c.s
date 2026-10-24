.setcpu "65816"
.segment "CODE"
.org $A21C
map_control_0ea21c:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
