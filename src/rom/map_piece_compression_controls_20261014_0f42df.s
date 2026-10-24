.setcpu "65816"
.segment "CODE"
.org $42DF
map_control_0f42df:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
