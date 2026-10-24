.setcpu "65816"
.segment "CODE"
.org $6AE7
map_control_0f6ae7:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
