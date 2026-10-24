.setcpu "65816"
.segment "CODE"
.org $A5B4
map_control_0ea5b4:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
