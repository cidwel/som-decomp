.setcpu "65816"
.segment "CODE"
.org $3BBF
map_control_0d3bbf:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
