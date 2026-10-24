.setcpu "65816"
.segment "CODE"
.org $BBF3
map_control_0dbbf3:
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
