.setcpu "65816"
.segment "CODE"
.org $1BBF
map_control_0e1bbf:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
