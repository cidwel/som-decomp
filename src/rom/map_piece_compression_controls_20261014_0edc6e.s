.setcpu "65816"
.segment "CODE"
.org $DC6E
map_control_0edc6e:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
