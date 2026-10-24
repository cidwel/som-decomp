.setcpu "65816"
.segment "CODE"
.org $BBF9
map_control_0dbbf9:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
