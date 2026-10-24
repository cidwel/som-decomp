.setcpu "65816"
.segment "CODE"
.org $A0A7
map_control_0ea0a7:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
