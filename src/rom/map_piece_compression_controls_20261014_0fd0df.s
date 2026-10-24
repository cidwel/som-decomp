.setcpu "65816"
.segment "CODE"
.org $D0DF
map_control_0fd0df:
    .byte $E1 ; previous-row copy count
