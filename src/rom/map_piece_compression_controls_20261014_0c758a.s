.setcpu "65816"
.segment "CODE"
.org $758A
map_control_0c758a:
    .byte $EE ; backreference distance high bits
    .byte $99 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
