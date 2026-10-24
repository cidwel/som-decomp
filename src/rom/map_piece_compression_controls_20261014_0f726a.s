.setcpu "65816"
.segment "CODE"
.org $726A
map_control_0f726a:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
