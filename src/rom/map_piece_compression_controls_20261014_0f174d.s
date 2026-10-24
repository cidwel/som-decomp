.setcpu "65816"
.segment "CODE"
.org $174D
map_control_0f174d:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
