.setcpu "65816"
.segment "CODE"
.org $8BCC
map_control_0e8bcc:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
