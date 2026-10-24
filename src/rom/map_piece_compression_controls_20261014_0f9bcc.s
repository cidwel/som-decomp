.setcpu "65816"
.segment "CODE"
.org $9BCC
map_control_0f9bcc:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
