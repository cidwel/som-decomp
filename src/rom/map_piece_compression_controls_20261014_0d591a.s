.setcpu "65816"
.segment "CODE"
.org $591A
map_control_0d591a:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
