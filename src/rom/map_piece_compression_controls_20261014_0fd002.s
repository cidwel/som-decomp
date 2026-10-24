.setcpu "65816"
.segment "CODE"
.org $D002
map_control_0fd002:
    .byte $C6 ; same-value copy count/distance
