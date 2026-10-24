.setcpu "65816"
.segment "CODE"
.org $93FC
map_control_0f93fc:
    .byte $E5 ; previous-row copy count
