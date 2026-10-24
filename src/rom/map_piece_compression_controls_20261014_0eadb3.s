.setcpu "65816"
.segment "CODE"
.org $ADB3
map_control_0eadb3:
    .byte $EC ; backreference distance high bits
    .byte $99 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
