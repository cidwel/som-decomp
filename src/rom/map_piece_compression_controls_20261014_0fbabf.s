.setcpu "65816"
.segment "CODE"
.org $BABF
map_control_0fbabf:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
